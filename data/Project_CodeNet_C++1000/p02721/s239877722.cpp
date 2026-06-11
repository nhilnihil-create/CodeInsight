#include<iostream>
#include<algorithm>
#include<iomanip>
#include<string>
#include<vector>

typedef unsigned long long ULL;
typedef long long LL;

using namespace std;

int main(){
    int N,K,C;
    int i;
    int *L,*R;

    string s;
    ULL patern = 0;
    int count;
    cin >> N >> K >> C;
    R = new int[K];
    L = new int[K];
    cin >> s;
    count = 0;
    for(i=0;i<N && count < K;){
        if( s[i] == 'o'){
            L[count++] = i;
            i += C+1;
        }else{
            i++;
        }
    }
    count = 0;
    for(i=N-1;i>=0 && count < K;){
        if( s[i] == 'o'){
            R[K-count-1] = i;
            count++;
            i -= C+1;
        }else{
            i--;
        }
    }
    /*
    for(i=0;i<K;i++){
        cout << "L:" << L[i]+1 << " R:" << R[i]+1 << endl;
    }
    */
    for(i=0;i<K;i++){
        if(L[i] == R[i]){
            cout << L[i] + 1 << endl;
        }
    }
    
    return 0;
}
