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

  vi v(n);

  for(int i=0; i<n; i++)

  cin>>v[i];

  int cnt=0;

  sort(v.begin(),v.end());

  for(int i=0; i<n; i++){

    for(int j=0; j<i; j++){

      for(int k=0; k<j; k++){

      if(v[i]<v[k]+v[j] && v[i]!=v[j] && v[j]!=v[k] && v[i]!=v[k])

      cnt++;

    }

    }

  }

  cout<<cnt<<endl;

}