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

  int n,x,t;

  cin>>n>>x>>t;

  int cn=0;

  while(n>0){

    n-=x;

    cn+=t;

  }

  cout<<cn<<endl;

}