#include<iostream>
#include<vector>
using namespace std;

vector<pair<long long, long long>> prime_factrization(long long n);


int main(){
    long long N, tmp, tmptmp;
    vector<pair<long long, long long>> prime_f;

    std::cin >> N;
    prime_f = prime_factrization(N);
    long long ans = prime_f.size();


    for(long long i = 0; i < prime_f.size(); i++){
        //std::cout << prime_f[i].first << " " << prime_f[i].second << "\n";
        if(prime_f[i].second > 1){
            tmp = 3;
            tmptmp = 2;

            while(tmp <= prime_f[i].second){
                ans = ans + 1;
                tmptmp++;
                tmp = tmp + tmptmp;
            }

        }
    }

    std::cout << ans;

}

vector<pair<long long, long long>> prime_factrization(long long n){
    vector<pair<long long, long long>> res;

    for(long long a = 2; a*a <= n; a++){
        if(n%a != 0){
            continue;
        }
        long long ex = 0;
        while(n%a == 0){
            ex++;
            n = n/a;
        }

        res.push_back({a,ex});
    }

    if(n != 1){
        res.push_back({n,1});
    }

    return res;

}