#include <bits/stdc++.h>

using namespace std;

int main(){
    unsigned long N;
    cin>>N;

    if(N%2==1){
        cout<<0<<endl;
        return 0;
    }

    unsigned long answer = 0;
    unsigned long pow5 = 10;
    for(int i=0; i<log(N)/log(5); ++i){
        answer += N / pow5;
        pow5 *= 5;
    }
    cout<<answer<<endl;

    return 0;
}


