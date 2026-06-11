#include <iostream>
using namespace std;

int main(){
    int N,K;
    int A;
    int snack[110]={0};

    cin >> N >> K;

    int i,j;
    int d;
    for(i=0; i<K; i++){
        cin >> d;
        for(j=0; j<d; j++){
            cin >> A;   
            if(snack[A-1]==0) snack[A-1]=1;
        }
    }

    int count=0;
    for(i=0; i<N; i++){
        if(snack[i]==0) count++;
    }

    cout << count << endl;

    return 0;
}