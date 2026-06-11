#include <iostream>

#include<vector>

#include<string>

#include<algorithm>

#include<cmath>

#include<cstdlib>

#include<utility> 

#include<cstdio> 

#define vii vector< pair<int,int> >

#define vi vector<int>

#define INF 1000000007

#define ff first

#define ss second

#define lli long long int

#define ulli unsigned long long int

using namespace std;

int main() {

 ios_base::sync_with_stdio(false);

    cin.tie(NULL);

  lli x,k,d;

  cin>>x>>k>>d;

  x=abs(x);

  if(x>0 && (x/d)>=k){

    cout<<abs(x-(k)*d);

  }

  else {

    lli ans=x-(x/d)*d;

    k-=x/d;

    if(k%2==0)

    cout<<ans;

    else cout<<min(abs(ans-d),abs(ans+d));

  }

  cout<<endl;

}