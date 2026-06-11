#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int N;cin >> N ;
    int s[N];
    int sum=0;
    for(int i=0;i<N;i++){
        cin >> s[i];
        sum+=s[i];
    }
    
    int dif=abs(sum-2*s[0]);
    for(int i=1;i<N-1;i++){
        int sum1=0;
        for(int j=0;j<=i;j++){
            sum1+=s[j];
        }
        dif=min(dif,abs(sum-2*sum1));
    }
    cout << dif;
}