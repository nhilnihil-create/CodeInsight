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
    for(int i=0;i<1000010;i++){
        if(i*8/100==a&&i/10==b){
            cout << i << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;

}