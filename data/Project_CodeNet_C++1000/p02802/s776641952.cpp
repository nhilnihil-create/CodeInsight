#include<iostream>
#include<vector>
//#include<algorithm>
using namespace std;

int main(){
long long N,M, P;
long long count_AC = 0, count_WA = 0;
string C;
std::cin >> N >> M;

vector<long long> correct_list(N,0);
vector<long long> WA_list(N,0);

for(long long i = 0; i < M; i++){
    std::cin >> P >> C;
    if(C == "AC"){
        if(correct_list[P-1] == 0){
            count_AC++;
            count_WA = count_WA + WA_list[P-1];
            correct_list[P-1] = 1;
        }
    }else{
        if(correct_list[P-1] == 0){
            WA_list[P-1]++;
        }
    }
}

std::cout << count_AC << " " << count_WA;
}