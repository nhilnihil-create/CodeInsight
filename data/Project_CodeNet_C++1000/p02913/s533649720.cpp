#include<iostream>
#include<string>
using namespace std;

#define len_MAX 5000
int A[len_MAX+1];

void Z_algorithm(string S){
    A[0] = S.size();
    int i = 1, j = 0;
    while (i < S.size()) {
        while (i+j < S.size() && S[j] == S[i+j]) ++j;
        A[i] = j;
        if (j == 0) { ++i; continue;}
        int k = 1;
        while (i+k < S.size() && k+A[k] < j) A[i+k] = A[k], ++k;
        i += k; j -= k;
    }
}

int main(){
    //input
    int N;
    cin >> N;
    string S;
    cin >> S;

    //calc
    int ans=0;
    int i,j;
    for(i=0; i<N; i++){
        Z_algorithm(S.substr(i));
        for(j=i+1; j<N; j++){
            ans=max(ans,A[j-i]-max(0,i+A[j-i]-1-j+1));
        }
    }

    //output
    cout << ans << endl;
    system("pause");
    return 0;
}