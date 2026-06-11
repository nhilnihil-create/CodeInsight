#include <iostream>
#include <vector>
#include <algorithm>

int n, sum;
int a[510], b[510];

int cnt(int m){
    int c = 0;
    for(int i=0;i<n;++i){
        b[i] = a[i]%m;
        c += b[i];
    }
    c/=m;
    std::sort(b,b+n);
    int s = 0;
    for(int i=0;i<n-c;++i)
        s+=b[i];

    return s;
}

std::vector<int> divi;

void init(){
    for(int i=1;i*i<=sum;++i) if(sum%i==0){
        divi.emplace_back(i);
        divi.emplace_back(sum/i);
    }
    std::sort(std::begin(divi),std::end(divi),std::greater<int>());
}

int main() {

    int k;

    std::cin >> n >> k;

    for(int i=0;i<n;++i){
        std::cin >> a[i];
        sum+=a[i];
    }

    init();

    int ans;

    for(int m : divi){
        if(cnt(m)<=k){
            ans=m;
            break;
        }
    }

    std::cout << ans << std::endl;
}
