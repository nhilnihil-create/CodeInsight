
#include <bits/stdc++.h>
#include <set>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++) 
#define ll long long
#define ld long double
#define repl(i, n) for (ll i = 0; i < (ll)(n); i++)  
#define outdeb(fir, sec, thr) cout << fir << ":" << sec << ":" << thr << endl
#define DEV_VAL 1000000007

template <typename T>
void inputList(vector<T>* list, int n, int sortType = 0)
{
  repl(i, n)
  {
    T tmp;
    cin >> tmp;
    list->push_back(tmp);
  }
  if(sortType == 1)
  {
    sort(list->begin(), list->end());
  }
  else if(sortType == 2)
  {
    sort(list->begin(), list->end(), greater<T>());
  }
}

int main()
{
  ll n;
  cin >> n;
  vector<ll> ilist;
  inputList(&ilist, n);

  bool isBuy = true;
  ll preMoney = 9999;
  ll stock = 0;
  ll money = 1000;

  repl(i, n)
  {
    if(isBuy)
    {
      if(preMoney >= ilist[i])
      {
        // より安いので買う
        money += preMoney * stock; // いったん買った金額で売る
        stock = money / ilist[i];
        money -= stock * ilist[i];
        preMoney = ilist[i];
      }
      else
      {
        // 高くなったので売る
        isBuy = false;
        money += stock * ilist[i];
        preMoney = ilist[i];
      }
    }
    else
    {
      if(preMoney <= ilist[i])
      {
        // より高いので売る
        money += stock * (ilist[i] - preMoney);
        preMoney = ilist[i];
      }
      else
      {
        // 安くなったので買う
        isBuy = true;
        stock = money / ilist[i];
        money -= stock * ilist[i];
        preMoney = ilist[i];
      }
      
    }
    
  }

  if(isBuy)
  {
    // 最後まで売れなかったものを買わなかったことにする
    money += stock * preMoney;
  }
  cout << fixed << money << endl;
  return 0;
}