#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,c,k,sum=0;
    cin >> a >> b >> c >> k;

    while(a>0 && k>0){
        sum += 1;
        a--; k--;
    }

    while(b>0 && k>0){
        b--; k--;
    }
  
    while(c>0 && k>0){
        sum -= 1;
        c--; k--;
    }
    cout << sum;
    return 0;
}
