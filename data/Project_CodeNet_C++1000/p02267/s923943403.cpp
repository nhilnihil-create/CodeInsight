#include<iostream>
using namespace std;

int  LinearSearch(int S[],int n,int T[],int q){

    int count=0;

    for(int i=0;i<q;i++){
        for(int j=0;j<n;j++){
            if(S[j] == T[i]){
                count++;
                break;
            }
        }
    }

    return count;
}

int main(){
    
    int n=0,q=0;

    cin >> n;
    int* S = new int[n];
    for(int i=0;i<n;i++){
        cin >> S[i];
    }

    cin >> q;
    int* T = new int[q];
    for(int i=0;i<q;i++){
        cin >> T[i];
    }

    cout << LinearSearch(S,n,T,q) << endl;

    return 0;
}