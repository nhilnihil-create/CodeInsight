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

  int n;

  cin>>n;

  vector<lli> a(n);

  for(int i=0; i<n; i++)

  cin>>a[i];

 //you have to keep track of previous max element

    lli ans=0,currmax=0;

    for(int i=0; i<n; i++){

      currmax=max(currmax,a[i]);

      ans+=currmax-a[i];

    }

    cout<<ans<<endl;

}