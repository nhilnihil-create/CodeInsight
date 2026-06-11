#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define MAX 100000
void inarray(int a[], int n){
    for(int i = 0; i < n; i++) cin >> a[i];
}

int main(){
    int h,w,a,b; cin >> h >> w >> a >> b;
    int M[h][w];
    int row[h+1], colom[w+1];
    for(int i = 0; i < h; i++) row[i] = 0;
    for(int i = 0; i < w; i++) colom[i] = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            M[i][j] = 0;
        }
    }

    // if(h == 1) b = 1;
    // if(w == 1) a = 1;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(i < b && j < a) M[i][j] = 0;
            if(i < b && j >= a) M[i][j] = 1;
            if(i >= b && j < a) M[i][j] = 1;
            if(i >= b && j >= a) M[i][j] = 0;

        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << M[i][j];
        }
        cout << endl;
    }
    return 0;
}