/* In the name of Allah */
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define debug cout << "here!"
#define pii pair<int , int>
#define pdd pair<double , double>
#define F first
#define S second
const int maxn = 1e5 * 5 + 10 , inf = 1e9 , pi = 3.14159265;
int x[maxn] , y[maxn] , n;
void solve(){
    
}
void in(){
    cin >> n;
    for (int i = 0; i < n;i ++){
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n - 2; i ++){
        if (x[i] == y[i] && x[i + 1] == y[i + 1] && x[i + 2] == y[i + 2]){
            cout << "Yes"; return ;
        }
    }
    cout << "No";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    in();
    return 0;
}
