#include <bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;
typedef vector< vector<char> > vvc;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef long long ll;

int main(){
    int a,b;
    cin >> a >> b;
    int m,n;
    m=a*100/8;
    if(m*8/100!=a) m++;
    n=b*10;
    //cout << m << " " << n << endl;
    if(m>n){
        if(m/10==b){
            cout << m << endl;
            return 0;
        }
    }else{
        if(n*8/100==a){
            cout << n << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}