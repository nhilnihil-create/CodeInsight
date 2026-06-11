#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> X(N,1);
    vector<int> H(N);
    for(int i=0; i<N; i++){
        cin >> H.at(i);
    }
    int a,b,less_h;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        a = a-1;
        b = b-1;
        if(H.at(a) < H.at(b)){
            X.at(a) = 0;
        }
        else if(H.at(a) > H.at(b)){
            X.at(b) = 0;
        }else if(H.at(a) == H.at(b)){
            X.at(a)=0;
            X.at(b)=0;
        }
    }
    int count = 0;
    for(int check: X){
        if(check == 1){
            count++;
        }
    }
    cout << count << endl;

}