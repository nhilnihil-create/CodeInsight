#include<iostream>
#include<string>
using namespace std;
main(){
    int i=0,A,B,C,K,ans=0;
    cin >> A >> B >> C >> K;
    if(A>=K){
        cout << K << endl;;
    }
    if(A+B>=K&&A<K){
        cout << A << endl; 
    }
    if(A+B<K){
        K=K-(A+B);
        cout << A-K << endl;
    }


    
}