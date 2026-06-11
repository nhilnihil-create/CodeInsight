#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

template<typename T>
void cout_vec(vector<T> &vec){
    for(int i=0; i<vec.size(); i++){
        if (i!=0){
            cout << ' ';
        }
        cout << vec[i];
    }
    cout << endl;
}

int main(){
    int N, K;
    cin >> N >> K;

    vector<int> vec(N+1);
    for(int i=0; i<N; i++){
        cin >> vec[i];
    }

    for(int i=0; i<K; i++){
        vector<int> nw(N+1,0);
        for(int j=0; j<N; j++){
            nw[max(0,j-vec[j])]++;
            nw[min(N,j+vec[j]+1)]--;
        }
        ll sum_=0;
        for(int k=0; k<N; k++){
            nw[k+1]+=nw[k];
            sum_+=(ll)nw[k];
        }
        vec.swap(nw);
        if(sum_==(ll)N*N){
            //cout << i << endl;
            break;
        }
        //cout << vec[0] << endl;
    }
    vec.pop_back();
    cout_vec(vec);
}