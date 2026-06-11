#include <bits/stdc++.h>
using namespace std;
/*2進数配列+1*/
vector<int> twoadd(vector<int> v, int N){
    v[N-1]+=1;
    int ind = N-1;
    int j=N-1;
    for(j=N-1;j>=1;j--){
        if(v[j]>1){
            v[j-1]+=1;
            v[j]=0;
        }
    }
    return v;
}
/*フィボナッチ*/
long long fibonatti(long long d){
    long long count = 0;
    long long f1 = 1;
    long long f2 = 1;/*ここを変える*/
    long long temp;
    if(d == 1){
        count = f1;
    }else if(d == 2){
        count = f2;
    }else if(d==0){
        count = 1;
    }else{
        for(int i=0;i<d-2;i++){
            temp = f1+f2;
            f1 = f2;
            f2 = temp;
        }
        count = temp;
    }
    return count;
}

/*ここから*/
int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> v(H, vector<int>(W));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            char w;
            cin >> w;
            if(w=='#'){
                v[i][j]=1;
            }else{
                v[i][j]=0;
            }
        }
    }
    int ans=0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            int count=0;
            if(v[i][j]==0){
                for(int k=i;k<H;k++){
                    if(v[k][j]==1){
                        break;
                    }
                    count++;
                }
                for(int k=i;k>=0;k--){
                    if(v[k][j]==1){
                        break;
                    }
                    count++;
                }
                for(int k=j;k<W;k++){
                    if(v[i][k]==1){
                        break;
                    }
                    count++;
                }
                for(int k=j;k>=0;k--){
                    if(v[i][k]==1){
                        break;
                    }
                    count++;
                }
            }
            if(ans<count){
                ans = count;
            }
            if(ans==H+W+2){
                break;
            }
        }
    }
    ans -= 3;
    cout << ans << endl;
}