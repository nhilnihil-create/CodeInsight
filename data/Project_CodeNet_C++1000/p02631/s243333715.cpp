#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<int>xor_values(n);
    int total_xor  = 0;
    for(int i = 0; i < n; i++){
        cin >> xor_values[i];
        total_xor = total_xor^xor_values[i];
    }
    //vector<int>res;
    for(int j = 0; j < n; j++){
        long long current_value  = xor_values[j];
        int result = 0;
        for(int i = 0; i < 32; i++){
            long long bit = (1 << i);
            int bit_value = current_value&bit;
            int xor_bit = total_xor&bit;
            if(bit_value == 0){
                result |= (bit&xor_bit);
            }else{
                result |= (bit^xor_bit);
            }
        }
        //res.push_back(result);
        cout << result << endl;
    }
    //for(int i = 0; i < n; i++){
        //int r = 0;
        //for(int j = 0; j < n; j++){
            //if(j!= i){
                //r ^= res[j];
            //}
        //}
        //cout << r << endl; 
    //}
    
}
