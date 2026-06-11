#include<bits/stdc++.h>
using namespace std;

int a[510][510] = {};

void solve(int left, int right, int level){
    if(left == right) return;
    if(left == right-1){
        a[left][right] = level;
        a[right][left] = level;
        return;
    }
    int mid = (left+right+1)/2;
    for(int l=left;l<mid;l++){
        for(int r=mid;r<=right;r++){
            a[l][r] = level;
            a[r][l] = level;
        }
    }
    solve(left, mid-1, level+1);
    solve(mid, right, level+1);
    return;
}

int main(){
    int N;

    cin >> N;
    solve(1, N, 1);
    for(int i=1;i<=N-1;i++){
        for(int j=1;j<=N;j++){
            if(j>i) cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}