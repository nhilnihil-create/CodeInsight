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
int n , x, p[101];
void solve(){
    
}
void in(){
    cin >> x >> n;
    for (int i = 0; i < n; i++){
        cin >> p[i];
    }
    for (int i = 0; i < 101; i ++){
        int a1 = x - i , a2 = x + i;
        bool check1 = 1 ,check2 = 1;
        for (int j = 0; j < n; j ++){
            if (p[j] == a1){
                check1 = 0;
            }
            if (p[j] == a2){
                check2 = 0;
            }
        }
        if (check1 == 1){
            cout << x - i;return ;
        }
        if (check2 == 1){
            cout << x + i; return ;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    in();
    return 0;
}
