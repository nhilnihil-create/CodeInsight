#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int N,K,c=0;
    cin >> N >> K;
    map<int,int> sunuke{};
    
    for(int i=0;i<N;i++){
        sunuke[i+1] = 0;
    }
    
    for(int i=0;i<K;i++){
        int d_i;    
        cin >> d_i;
        for(int j=0;j<d_i;j++){
            int a_i;
            cin >> a_i;
            sunuke[a_i] += 1;
        }
    }
    
    for(int i=0;i<N;i++){
        if(sunuke[i+1] == 0) c++;
    }
    
    cout << c <<endl;
}