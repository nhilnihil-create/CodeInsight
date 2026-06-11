#include<iostream>
int main(){
        int P,Q,R;
        std::cin >> P >> Q >> R;
        int min = P+Q;
        if(Q+R < min) min = Q+R;
        if(P+R < min) min = P+R;
        std::cout << min;
}