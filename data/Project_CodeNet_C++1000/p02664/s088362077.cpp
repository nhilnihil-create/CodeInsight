#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>

#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define PI 3.141592653589
#define MOD 1000000007

using namespace std;

int gcd(int a, int b){return (a % b)? gcd(b, a % b) : b;}
int lcm(int a, int b){return a * b / gcd(a, b);}

void solve_A(){
    int h1, m1, h2, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;

    int hour1 = h1 * 60 + m1;
    int hour2 = h2 * 60 + m2;
    cout << hour2 - hour1 - k << endl;
}

void solve_B(){
    string t;
    cin >> t;

    int n = t.size();
    
    for(int i = 0; i < n; i++){
        if(t[i] != '?') cout << t[i];
        else if(i != 0 && t[i-1] == 'P' && t[i] == '?'){
            cout << 'D';
        }
        else if(i != n-1 && t[i] == '?' && t[i+1] == 'D'){
            cout << 'P';
        } else cout << 'D';
    }
    cout << endl;
}

int main(void){
    solve_B();
    
    return 0;
}