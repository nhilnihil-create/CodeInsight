#include <bits/stdc++.h>
using namespace std;
int main(){
    int H, W, A, B;
    cin >> H >> W >> A >> B;
    if(A == 0 && B == 0){
        for(int i = 0; i < H; i++){
            vector<int> v(W, 0);
            for(int j = 0; j < W; j++) cout << v[i];
            cout << endl;
        }
    }
    else if(A == 0 && B != 0){
        for(int i = 0; i < H; i++){
            if(i < B){
                vector<int> v(W, 1);
                for(int j = 0; j < W; j++) cout << v[j];
                cout << endl;
            }
            else{
                vector<int> v(W, 0);
                for(int j = 0; j < W; j++) cout << v[j];
                cout << endl;
            }
        }
    }
    else if(A != 0 && B == 0){
        for(int i = 0; i < H; i++){
            vector<int> v(W, 0);
            for(int j = 0; j < W; j++){
                if(j < A) v[j] = 1;
                cout << v[j];
            }
            cout << endl;
        }
    }
    else{
        for(int i = 0; i < H; i++){
            vector<int> v(W, 0);
            for(int j = 0; j < W; j++){
                if(i < B && j < A) v[j] = 1;
                else if(i >= B && j >= A) v[j] = 1;
                cout << v[j];
            }
            cout << endl;
        }
    }
}