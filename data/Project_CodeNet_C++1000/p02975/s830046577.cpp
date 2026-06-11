#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

map<int, int> cnt;
int a[100005];

int main(){
    int N, temp = 0;
    cin >> N;
    for(int i=1; i<=N; i++){
        int num;    
        cin >> num;
        cnt[num]++;
        if(i == 1){
            temp++;
            a[temp] = num;
        } else if(cnt[num] == 1){
            temp++;
            a[temp] = num;
        }
    }
    sort(a+1, a+temp+1);
    if (temp > 3){
        cout << "No" << endl;
    } else if(a[1] == 0 && cnt[0] == N){
        cout << "Yes" << endl;
    }else if (N % 3 != 0){
        cout << "No" << endl;
    } else if(a[1] == 0 && cnt[a[2]] == 2*N/3 && temp == 2){
        cout << "Yes" << endl;
    } else if(cnt[a[1]] == N/3 && cnt[a[2]] == N/3 ){
        if((a[1]^a[2]^a[3]) == 0){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        cout << "No" << endl;
    }
}