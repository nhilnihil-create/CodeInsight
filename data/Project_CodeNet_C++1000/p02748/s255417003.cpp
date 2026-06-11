#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {

ll ans=1e9;

int mina=1e9,minb=1e9;
int AA,BB,M;
cin >> AA >> BB >>M;


vector<ll>A(AA);
vector<ll>B(BB);

rep(i,AA)
{int a;
 cin>>a;
 A[i]=a;
 mina=min(a,mina);
}
rep(i,BB)
{int b;
cin>>b;
B[i]=b;
minb=min(b,minb);}

ans=mina+minb;
//cout<<ans<<" "<<mina<<" "<<minb<<endl;
rep(i,M)
{ll x,y,c;
 cin>>x>>y>>c;
 //cout<<x<<" y:"<<y<<" c:"<<c<<endl;
 //cout<<A[x-1]<<" "<<B[y-1]<<endl;
 ans=min(ans,A[x-1]+B[y-1]-c);}

cout<<ans<<endl;


}
/*vector <int> a(3);
for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }*/