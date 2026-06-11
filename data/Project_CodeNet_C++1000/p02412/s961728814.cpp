#include<iostream>
using namespace std;
int main(){
    int n, x;
    cin >> n >> x;
    int i,j,k,total=0;
    while(n!=0||x!=0){
        for(i=1;i<n-1;i++){
            for(j=i+1;j<n;j++){
                for(k=j+1;k<n+1;k++){
                    if(x==i+j+k) total+=1;
                }
            }
        }
        cout << total << endl;
        cin >> n >> x;
        total = 0;
    }
    return 0;
}
