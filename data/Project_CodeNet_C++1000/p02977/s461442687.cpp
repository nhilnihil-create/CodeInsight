#include <iostream>
#include <vector>

using namespace std;

int pow2[18];

int main(){
    int N;
    cin >> N;
    pow2[0] = 1;
    for(int i = 1; i <= 17; i++){
        pow2[i] = pow2[i-1]*2;
    }
    int m;
    for(int i = 0; i <= 17; i++){
        if(N == pow2[i]){
            cout << "No" << endl;
            return 0;
        }
        if(pow2[i] > N){
            m = i;
            break;
        }
    }
    cout << "Yes" << endl;
    if(N == 3){
        for(int i = 1; i <= 5; i++){
            cout << i << ' ' << i+1 << endl;
        }
    }else if(N%2 == 0){
        vector<int> buf;
        buf.push_back(1);
        int tmp = N-pow2[m-1]+1;
        buf.push_back(tmp);
        for(int i = 2; i < pow2[m]; i++){
            if(i != tmp) buf.push_back(i);
        }
        for(int i = 0; i < pow2[m-1]-2; i++){
            cout << buf[i] << ' ' << buf[i+1] << endl;
        }
        cout <<  buf[pow2[m-1]-2] << ' ' << buf[0]+N << endl;
        for(int i = 0; i < pow2[m-1]-2; i++){
            cout << buf[i]+N << ' ' << buf[i+1]+N << endl;
        }
        for(int i = pow2[m-1]; i <= N-2; i+=2){
            cout << 1 << ' ' << i << endl;
            cout << i << ' ' << i+1 << endl;
            cout << 1 << ' ' << i+N+1 << endl;
            cout << i+N+1 << ' ' << i+N << endl;
        }
        cout << N << ' ' << pow2[m-1] << endl;
        cout << tmp << ' ' << 2*N << endl;
    }else{
        for(int i = 1; i <= pow2[m-1]-2; i++){
            cout << i << ' ' << i+1 << endl;
        }
        cout <<  pow2[m-1]-1 << ' ' << 1+N << endl;
        for(int i = 1; i <= pow2[m-1]-2; i++){
            cout << i+N << ' ' << i+N+1 << endl;
        }
        for(int i = pow2[m-1]; i <= N-1; i+=2){
            cout << 1 << ' ' << i << endl;
            cout << i << ' ' << i+1 << endl;
            cout << 1 << ' ' << i+N+1 << endl;
            cout << i+N+1 << ' ' << i+N << endl;
        }
    }
}