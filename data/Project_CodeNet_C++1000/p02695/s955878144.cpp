#include <bits/stdc++.h>
using namespace std;

struct abcd{int a,b,c,d;};
abcd abcd_array[55];

int calc_tokuten(vector<int> array,int q){
    int sum = 0;
    for(int i=0;i<q;i++){
        //cout << abcd_array[i].b-1 << " " << abcd_array[i].a -1 << endl;
        if (array.at(abcd_array[i].b - 1) - array.at(abcd_array[i].a -1) == abcd_array[i].c){
            sum += abcd_array[i].d;
        }
    }
    return sum;
}

void func(int m,vector<int> &array,int keta,int q,vector<int> &sum_array){
    if(keta == -1){
        int s = calc_tokuten(array,q);
        sum_array.push_back(s);
        return;
    }
    for(int i=1;i<=m;i++){
        array.at(keta) = i;
        func(i,array,keta-1,q,sum_array);
    }
}



int main(){
    int n,m,q;
    cin >> n >> m >> q;
    vector<int> array(n),sum_array(0);
    for(int i=0;i<q;i++) cin >> abcd_array[i].a >> abcd_array[i].b >> abcd_array[i].c >> abcd_array[i].d;
    func(m,array,n-1,q,sum_array);

    int maxi = -1;
    for(int i=0;i<sum_array.size();i++){
        if(maxi < sum_array.at(i)) maxi = sum_array.at(i);
    }
    cout << maxi << endl;
}