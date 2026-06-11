#include<iostream>
#include<algorithm>

using namespace std;

int p[101] = {};
int q[101] = {};

int main(){
    int X, N = 0;
    cin >> X >> N;
  	if(N == 0){
      cout << X << endl;
      return 0;
    }
    int flag = 1;
    for(int i = 0; i < N; i++){
        cin >> p[i];
        if(p[i] == X){
            flag = 0;
        }
    }
    if(flag){
        cout << X << endl;
        return 0;
    }
    int result = 0;
    for(int i = 0; i < 100; i++){
        flag = 1;
        for(int j = 0; j < N; j++){
            if(p[j] == X - i){
                flag = 0;
                break;
            }
        }
        if(flag){
            cout << X - i << endl;
            return 0;
        }
        flag = 1;
        for(int j = 0; j < N; j++){
            if(p[j] == X + i){
                flag = 0;
                break;
            }
        }
        if(flag){
            cout << X + i << endl;
            return 0;
        }
    }
    return 0;
}