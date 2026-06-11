#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N=0,cnt=0;
    cin>>N;
    while(N!=0){
        if((N%10)==7){
            cnt++;
        }
        N=N/10;
    }
    if(cnt>0){
        cout<< "Yes";
    }
    else{
        cout<< "No";
    }
    return 0;
}
