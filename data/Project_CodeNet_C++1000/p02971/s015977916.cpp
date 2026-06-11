#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 1000000007;

int main(){
    int n;
    cin >> n;
    P mx1 = P(0, -1), mx2 = P(0, -1);
    rep(i, n){
        int num;
        cin >> num;
        if(num > mx1.first){
            swap(mx1, mx2);
            mx1.first = num;
            mx1.second = i;
        }else{
            if(num > mx2.first){
                mx2.first = num;
                mx2.second = i;
            }
        }
    }
    rep(i, n){
        if(mx1.second != i) cout << mx1.first << endl;
        else cout << mx2.first << endl;
    }
}