#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define ins insert
#define vi vector<int>
const int mxN=1e6;

int main()
{
    int n;
    cin >> n;
  	if(n%1000==0)
      	cout << 0;
 	else
    cout << 1000-n%1000;
}