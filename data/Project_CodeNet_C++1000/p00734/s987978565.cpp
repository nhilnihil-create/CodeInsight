#include <iostream>
#include <cstdio>
#include <numeric>
#include <vector>

void search_diff(std::vector<int> v1, std::vector<int> v2, int v1_sum, int v2_sum) {
    int abs, r1=-1, r2=-1;
    for(int e1 : v1) {
        for(int e2 : v2) {
            if(v1_sum+e2-e1 == v2_sum+e1-e2) {
                if(r1+r2<0 || (r1+r2)>(e1+e2) ) {
                    r1 = e1; r2 = e2;
                }
            }
        }
    }

    if(r1+r2 < 0) {
        std::cout<<-1<<std::endl;
    } else {
        std::cout<<r1<<" "<<r2<<std::endl;
    }
    return;
}

int main() {
    int n, m, data, tarou_sum, hanako_sum;
    std::cin>>n>>m;
    do {
        std::vector<int> tarou, hanako;
        for(int i=0; i<n; i++) {
            std::cin>>data;
            tarou.push_back(data);
        }
        for(int i=0; i<m; i++) {
            std::cin>>data;
            hanako.push_back(data);
        }

        tarou_sum = std::accumulate(tarou.begin(), tarou.end(), 0);
        hanako_sum = std::accumulate(hanako.begin(), hanako.end(), 0);

        search_diff(tarou, hanako, tarou_sum, hanako_sum);

        std::cin>>n>>m;
    }while(n!=0 && m!=0);

    return 0;
}

