#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >>N;
    vector<int> L(N);
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }
    long long sum=0;
    if(N==1||N==2){
        cout << 0 << endl;
    }
    else{
        for(int i=0;i<N-2;i++){
            for(int j=1;j<N-1;j++){
                for(int k=2;k<N;k++){
                    if(L[i]!=L[j]&&L[j]!=L[k]&&L[k]!=L[i]){ //全部違うとき
                        if(
                            L[i]+L[j]>L[k]&&L[j]+L[k]>L[i]&&L[k]+L[i]>L[j]&&i<j&&j<k
                        ){
                            sum+=1;
                        }
                    }
                }
            }
        }
        cout<<sum<<endl;
    }
}