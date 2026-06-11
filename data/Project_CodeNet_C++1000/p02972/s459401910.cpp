#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using Graph = vector<vector<ll>>;
using P = pair<int,int>;
#define MOD 1000000007
#define INF 1000000

/*
N=2*10^5
N個の箱に番号1-Nが書いてある
任意の整数i(1<=i<=N)に対して
iの倍数の番号の箱のボールの総和 %2 ==ai
*/

int main()
{
  int N;cin>>N;
  vector<int> a(N+1);
  for (int i=1;i<=N;i++)
    cin>>a[i];
  vector<int> b(N+1,0);
  
  for (int i=N;i>=1;i--)
  {
    //Nの倍数から順番に入れていく
    //iの倍数を足して、２で割ってa[i]と一致したら0
    //一致しなければ1をたす？？
    int d=1;
    int sum=0;
    while (d*i<=N)
    {
      sum += b[d*i];
      d++;
    }
    //cout<<i<<" "<<sum<<endl;
    if (sum % 2 != a[i]) b[i]=1;
  }
  
  //for (int i=1;i<=N;i++)
    //cout<<"b["<<i<<"]="<<b[i]<<endl;
  
  int count=0;
  for (int i=1;i<=N;i++)
  {
    if (b[i]==1) count++; 
  }
  cout<<count<<endl;
  for (int i=1;i<=N;i++)
  {
    if (b[i]==1) cout<<i<<" "; 
  }
}