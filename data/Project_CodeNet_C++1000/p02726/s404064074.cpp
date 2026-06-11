#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


int min_tri(int x, int y, int z);
int my_abs(int x);

int main(){
    int N, X, Y;
    int pair_, ans_tmp1, ans_tmp2, ans_tmp3;
    std::cin >> N >> X >> Y;
    vector<int>  ans(N-1,0);

    for(int k = 1; k <= N-1; k++){
        for(int j = k + 1; j <= N; j++){
            ans_tmp1 = j - k;
            ans_tmp2 = my_abs(X-k) + 1 + my_abs(Y - j);
            ans_tmp3 = my_abs(Y-k) + 1 + my_abs(X - j);

            pair_ = min_tri(ans_tmp1, ans_tmp2, ans_tmp3);
            //std::cout << pair_ << "\n";
            ans[pair_ - 1]++;
        }

    }

    for(int i = 0; i < ans.size();i++){
        std::cout << ans[i] << "\n";
    }


}

int min_tri(int x, int y, int z){
    int ans;
    if(x < y){
        if(x < z){
            ans = x;
        }else{
            ans = z;           
        }
    }else{
        if(y < z){
            ans = y;
        }else{
            ans = z;
        }
    }
    return ans;
}

int my_abs(int x){
    if(x < 0){
        return -x;        
    }else{
        return x;
    }
    
}