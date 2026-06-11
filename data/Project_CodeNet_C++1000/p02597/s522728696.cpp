#include <bits/stdc++.h>
#include <chrono>
#include <math.h>
using namespace std;
using ll = long long;
using ld = long double;
using namespace std::chrono; 
#define fo(i,z,n) for(int i = z;i<n;i++)
#define Fo(i,z,n) for(ll i = z;i<n;i++)
#define INT_BITS 32
#define mod 1000000007
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int> >
#define vvl vector<vector<ll> > 
#define pb push_back
#define f first
// #define s second
#define int long long
#define float long double
#define all(c) (c).begin(), (c).end()
#define endl '\n'




int32_t main()
{
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     cout.tie(0);
   	
     // int t;
     // cin >> t;

     // while(t--){
 		

     // }

     int n;
     cin >> n;
     string arr;
    	cin >> arr;
     int i = 0;
     int j = n-1;
     int count = 0;
     while(i < j){
     	while(i < j && arr[i] == 'R')i++;
     	while(i < j && arr[j] == 'W')j--;
    	if(i < j){
    		swap(arr[i],arr[j]);
    		j--;
    		i++;
    		count++;
    	}

     }
     cout << count << endl;



return 0;
}


