#include<iostream>
#include<vector>
using namespace std; 
vector<long long> L;
int main(void){
    int N,ans = 0;
    cin >> N;
    L = vector<long long>(N);
    for(int i=0;i<N;i++){
        cin >> L[i];
    }
    for(int i=0;i<N-2;i++){
        for(int j=i+1;j<N-1;j++){
            for(int k=j+1;k<N;k++){
                int a=L[i],b=L[j],c=L[k];
                if(a!=b && b!=c && a!=c){
                    if((a+b>c)&&(a+c>b)&&(c+b>a)){
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}