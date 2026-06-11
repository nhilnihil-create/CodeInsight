#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define all(x) (x).begin(),(x).end()
#define desc greater<int>()
#define pb(x) push_back(x)
ll gcd(ll a, ll b) { return (!a)?b:gcd(b%a,a);}
ll lcm(ll x,ll y){return x*(y/gcd(x,y));}
void pArr(int arr[], int s);
void pVec(vector<int> v);
bool isPrime(int x);
int binarySearch(int arr[], int l, int r, int x);
int vBinarySearch(vector<ll> v, int l, int r, ll x);
int nChoosek( int n, int k );
int mod=1e9+7;

void solve(){
    int a,b;
    cin >> a >> b;
    if (b==1){
        cout << 0 << endl;
    }
    else{
        if (b-a<=0){
            cout << 1 << endl;
        }
        else{
            b-=a;
            int r=(b%(a-1)==0)?0:1;
            cout << b/(a-1)+r+1 << endl;
        }
    }
}



int main(){
/*
    string temp;
    int t;
    cin >> t;
    getline(cin, temp);
    while (t--){
        solve();
    }
*/
    solve();
    return 0;
}


void pArr(int arr[], int s){
    for (int i=0;i<s;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void pVec(vector<int> v){
    for (int i=0;i<v.size();i++){
        cout << v.at(i) << " ";
    }
    cout << endl;
}
bool isPrime(int x){
    if (x==1){
        return false;
    }
    if(x==2){
        return true;
    }
    for (int i=2;i<=(int)(pow(x,0.5));i++){
        if (x%i==0){
            return false;
        }
    }
    return true;
}

int vBinarySearch(vector<ll> v, int l, int r, ll x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (v.at(m) == x)
            return m;
        if (v.at(m) < x)
            l = m + 1;
        else
            r = m - 1;
    }
    //bigger
    return r+1;
}

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    //smaller
    return r;
}

int nChoosek( int n, int k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}
