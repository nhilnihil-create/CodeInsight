/*
20/7/27
*/
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
    long long x;
    cin >> x;
    for(int i=0;i<1000;i++){
        bool flag=0;
        for(int j=-1000;j<1000;j++){
            if(x==i*i*i*i*i-j*j*j*j*j){
                cout << i << " " << j << endl;
                flag=1;
                break;
            }
        }
        if(flag) break;
    }
}