#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int N,i,j,k,cm,count;
    bool flag;
    flag=false;
    cin >> N>>cm;
    count=0;
    long long int S[200010];

    for (i=0;i<N;i++){
        cin>>S[i];
        if (S[i]>=cm){
            count+=1;
        }
    }

    
        cout << count <<endl;
    
    return 0;
    
}
