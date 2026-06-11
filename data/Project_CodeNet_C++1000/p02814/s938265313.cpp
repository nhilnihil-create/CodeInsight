//半公倍数：１．５倍、２．５倍。。。
//3以上の奇数倍、割る２
//互いに素であった場合は存在しないのでは？→存在する。
//最小半公倍数が存在する場合は、それの奇数倍で求まる気がする。
//最小半公倍数が存在しない場合は、存在しない。
//どのような時に存在しないのか？
//素因数分解したときの因数２の数が異なる場合は、存在しない。
//最小半公倍数の求め方
//２で割った値が互いに素であれば、２で割った値を全てかければよい。
//互いに素でない場合は少ない方の値で大きい方の値を割る。
#include <bits/stdc++.h>
using namespace std;
vector <long long> primeNumbers;
bool isPrime(long long n){
    //cout << n << endl;
    if(n==0)return false;
    if(n==1)return false;
    if(n==2)return true;
    double sq = sqrt(n);
    for(long long i = 2; i <= sq; i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
void getPrimeNumbers(long long n){
    //cout << "getPrimeNumbers" << endl;
    //cout << n << endl;
    if(isPrime(n)){
        primeNumbers.push_back(n);
        return;
    }
    double sq = sqrt(n);
    if(n==1){
        return;
    }
    for(long long i = 2; i<=sq; i++ ){
        if(n%i==0){
            //cout << n << endl;
            if(isPrime(i))primeNumbers.push_back(i);
            getPrimeNumbers(n/i);
            break;
        }
    }
}
bool isSemiCommonMulti(long long value, vector <long> &v){
    //cout << value << endl;
    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        if(value%(v[i]/2)==0){
            cout << "test" << endl;
            long long div = value/(v[i]/2);
            if(div%2==1){
                cout << "semi common multi" << endl;
                cnt++;
            }
        }
    }
    if(cnt==v.size()){
        return true;
    }else{
        return false;
    }
}
bool checkSemiMulti(long long num, vector <long> &v){
    bool isAvailable = true;
    for(long j = 0; j < v.size(); j++){
        if(num%(v[j]/2)==0){
            long div = num/(v[j]/2);
            if(div%2==1){
                continue;
            }else{
                isAvailable=false;
            }
        }else{
            isAvailable=false;
        }
    }
    return isAvailable;
}
int main(){
    long n,m;
    cin >> n >> m;
    vector <long> p(n);
    vector <long> harfP(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());
    

    vector <long long> candidate;
    long long tmp = p.back()/2;
    long long value = 1;
    long long cnt = 0;
    value=tmp*(2*cnt+1);
    long long smallestOne = -1;
    while(value<=m){
        //cout << value << endl;
        if(checkSemiMulti(value,p)){
            smallestOne = value;
            break;
        }else{
            cnt++;
            value=tmp*(2*cnt+1);
        }
    }
    if(smallestOne<0){
        cout << 0 << endl;
    }else{
        if((m/smallestOne)%2==0){
            cout << m/smallestOne/2 << endl;        
        }else{
            cout << m/smallestOne/2+1 << endl;        
        }
    }
    return 0;
}