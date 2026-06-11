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

vector<int> primes(0);
void prime_number(int N){
    vector<int> tmp(N+1,1);
    tmp[0]=tmp[1]=0;
    for(int i=2; i<=N; i++){
        if(tmp[i]==1){
            primes.push_back(i);
        }
        for(long long j= (long long) i*i; j<=N; j+=i){
            tmp[j]=0;
        }
    }
}

vector<int> factorize(int x){
    vector<int> ret(primes.size(),0);
    for(int i=0; i<primes.size(); i++){
        int p=primes[i];
        while(x%p==0){
            x/=p;
            ret[i]++;
        }
    }
    if(x!=1){
        primes.push_back(x);
        ret.push_back(1);
    }
    return ret;
}

int main(){
    int N, K;
    cin >> N >> K;

    vector<int> A(N,0);
    int sum_=0;
    for(int i=0; i<N; i++){
        cin >> A[i];
        sum_+= A[i];
    }

    deque<int> factor;
    for(int i=30000; i>=1; i--){
        if(i*i>sum_){
            continue;
        }
        if(sum_%i==0){
            factor.push_front(sum_/i);
            factor.push_back(i);
        }
    }

    for(auto it=factor.begin(); it!=factor.end(); it++){
        int i=*it;
        int tmp1=0;
        int tmp2=0;
        priority_queue<int, vector<int>, less<int> > que1;
        priority_queue<int, vector<int>, less<int> > que2;

        for(int j=0; j<N; j++){
            int r =A[j]%i;
            if(r<i-r){
                tmp1+=r;
                que1.push(r);
            }else{
                tmp2+=i-r;
                que2.push(i-r);
            }
        }

        int diff=tmp1-tmp2;
        if(diff>0){
            int cnt =diff/i;
            for(int j=0; j<cnt; j++){
                int x=que1.top();
                que1.pop();
                tmp1-=x;
            }
        }else{
            int cnt=-diff/i;
            for(int j=0; j<cnt; j++){
                int x=que2.top();
                que2.pop();
                tmp1+=i-x;
            }
        }
        if(tmp1<=K){
            cout << i << endl;
            return 0;
        }
    }


}