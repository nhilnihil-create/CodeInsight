#include<bits/stdc++.h>
using namespace std;
using ll = long long;

double per(double n){
    if(n == 1) return n;
    return n*per(n-1);
}

int main(){
    int n;
    cin >> n;
    vector<int>p(n), q(n);
    for(int i=0;i<n;i++) cin >> p[i];
    for(int i=0;i<n;i++) cin >> q[i];

    vector<int>t(n);
    for(int i=0;i<n;i++) t[i] = i+1;


    vector<vector<int>>vec;
    do{
        vec.push_back(t);
    }while(next_permutation(t.begin(), t.end()));

    int a = -1, b = -1;
    for(int i=0;i<vec.size();i++){
        if(a < 0){
            bool end = true;
            for(int j=0;j<n;j++)if(vec[i][j] != p[j]) end = false;
            if(end) a = i;
        }if(b < 0){
            bool end = true;
            for(int j=0;j<n;j++)if(vec[i][j] != q[j]) end = false;
            if(end) b = i;
        }
    }

    cout << abs(a-b) << endl;
}
