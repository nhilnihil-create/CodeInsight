#include<bits/stdc++.h>
#include<string>
#include<cmath>

using namespace std;

#define ll long long int
#define ld long double
#define loop(i, n) for (int i = 0; i < n; i++)
#define loops(i, s, n) for (int i = s; i < n; i++)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define deb(x) cout<< #x << '=' << x <<endl
#define MOD 1000000007
const int N = 2e5 + 10;
int n,k;
vector<int> b(N,0);
int a[N];
void simulate(){
    for(int i = 0; i<n; i++){
        int l = max(0, i - a[i]);
        int r = min(n - 1,i + a[i]);
        b[l]++;
        b[r + 1]--;
    }
    for(int i = 1; i<n; i++){
        b[i] += b[i-1];
    }
    for(int i = 0; i<n; i++){
        a[i] = b[i];
        b[i] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    cin>>n>>k;
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    for(int i = 0; i<k; i++){
        simulate();
        bool f = false;
        for(int j = 0; j<n; j++){
            if(a[j] != n){
                f = true;
            }
        }
        if(!f){
            break;
        }
    }
    for(int i = 0; i<n; i++){
        cout<<a[i]<<" ";
    }
}