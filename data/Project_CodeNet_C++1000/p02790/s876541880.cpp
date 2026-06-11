#include<bits/stdc++.h>

using namespace std;
#define Pi acos(-1)
#define _terminated return 0
#define endl "\n"
#define yes cout << "yes" << endl 
#define no cout << "no" << endl 
#define booster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<long> > v2l;

const int mod = 1e+5;
const int mx = 2e+5;
const ll inf = 1e18;

using namespace std;
#define max 101 
void solvio(){ 	
     int a,b,i; 
     cin >> a >> b; 
    if(a>b){ 
        for(i=1; i<=a; i++) cout << b;
         } else{
         for(i=1; i<=b; i++)
            cout << a; 
        } 
    cout << endl;
    
}

int main(){ 
    booster;
    solvio(); 
    _terminated;
}