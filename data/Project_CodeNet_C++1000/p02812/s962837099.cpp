#include <iostream>
#include <string>
using namespace std;
int main(void){
    // Your code here!
    int N,i,j,k,count;
    string S;
    bool flag;
    count=0;
    flag=false;
    cin >> N;
    cin >> S;
    
    for (i=0;i<=N-2;i++){
        
        if(S[i]=='A' && S[i+1]=='B' && S[i+2]=='C'){
            count+=1;
        }
        
    }
    
    cout << count<<endl;

    return 0;
    
}
