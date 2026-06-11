#include<iostream>
using namespace std;

int main(void){
    unsigned long n,m=0;
    int k=0;


    cin >> n >> k;
    if(n<1||1000000000<n||k<2||10<k)
        return 0;
    for(int i=0;i<n;i++){
        if(i==0)
            m+=k;
        else if(i!=0)
            m*=k;
        if(m>n){
                cout << i+1 << endl;
            break;
        }
    }
    return 0; 
}