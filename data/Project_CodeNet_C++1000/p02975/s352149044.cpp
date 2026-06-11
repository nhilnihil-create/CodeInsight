#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<ll,ll>;

int main()
{
  ll N;
  cin >> N;

  ll flag2 = 0;
  vector<ll> A(N);
  REP(i, N){
    cin >> A[i];
    if(A[i]==0){
      flag2 = 1;
    }
  }
  

  map<ll,ll> mp;
  REP(i,N){
    mp[A[i]]++;
  }
  // for(auto z:mp){
  //   cout << z.first << " " << z.second << endl;
  // }

  ll flag = 0;
  if(flag2 == 1){
  //0が含まれる場合
    if(mp.size()==1){
      //0だけの場合
      flag = 1;
    }else if(mp.size()==2){
      //0ともう一種類だけの場合
      ll y = mp[0];
      for(auto x:mp){
        if(x.first!=0&&x.second==y*2){
          flag=1;
        }
      }
    }
  }else{
    //0が含まれない場合
    if(mp.size()==3){
      vector<P> pr(3);
      ll i = 0;
      for(auto x:mp){
        pr.at(i).first=x.first;
        pr.at(i).second=x.second;
        i++;
      }
      // REP(i,3){
      //   cout << pr.at(i).first << " " << pr.at(i).second << endl;
      // }
      if(pr.at(0).second==pr.at(1).second&&pr.at(0).second==pr.at(2).second){
        if((pr.at(0).first^pr.at(1).first^pr.at(2).first)==0){
          flag=1;
        }
      }
    }
  }

  if(flag==1){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  // if(N%3!=0){
  //   if(mp.size()!=1&&mp[0]==0){
  //     cout << "No" << endl;
  //   }else{
  //     cout << "Yes" << endl;
  //   }
  // }else{
  //   if(mp.size()!=3){
  //     if(mp.size()!=2){
  //       if(mp.size()!=1){
  //         cout << "No" << endl;
  //       }else{
  //         if(mp[0]!=0){
  //           cout << "Yes" << endl;
  //         }else{
  //           cout << "No" << endl;
  //         }
  //       }
  //     }else{
  //       vector<P> pr(2);
  //       int i = 0;
  //       for(auto x:mp){
  //         pr.at(i).first=x.first;
  //         pr.at(i).second=x.second;
  //         i++;
  //       }
  //       // REP(i,2){
  //       //   cout << pr.at(i).first << " " << pr.at(i).second << endl;
  //       // }
  //       if(pr.at(0).second==pr.at(1).second*2){
  //         if(pr.at(0).first^pr.at(0).first==pr.at(1).first){
  //           cout << "Yes" << endl;
  //         }else{
  //           cout << "No" << endl;
  //         }
  //       }else if(pr.at(1).second==pr.at(0).second*2){
  //         if(pr.at(1).first^pr.at(1).first==pr.at(0).first){
  //           cout << "Yes" << endl;
  //         }else{
  //           cout << "No" << endl;
  //         }
  //       }else{
  //         cout << "No" << endl;
  //       }
  //     }
  //   }else{
  //     vector<P> pr(3);
  //     int i = 0;
  //     for(auto x:mp){
  //       pr.at(i).first=x.first;
  //       pr.at(i).second=x.second;
  //       i++;
  //     }
  //     // REP(i,3){
  //     //   cout << pr.at(i).first << " " << pr.at(i).second << endl;
  //     // }
  //     if(pr.at(0).second!=pr.at(1).second||pr.at(0).second!=pr.at(2).second){
  //       cout << "No" << endl;
  //     }else{
  //       if(pr.at(0).first^pr.at(1).first==pr.at(2).first){
  //         cout << "Yes" << endl;
  //       }else{
  //         cout << "No" << endl;
  //       }
  //     }
  //   }
  // }
}