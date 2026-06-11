#include<iostream>
#include<vector>
using namespace std;


int main(){
    int n;
    long long k;
    cin >> n >> k;
    int a[n];
    vector<int> G[n];
    vector<int> c(n ,INT_MAX);
    vector<int> b(n ,INT_MAX);
    for(int i = 0;i < n;i++){
        cin >> a[i];
        a[i]--;
        G[i].push_back(a[i]);
    }
    /**/
    int counter  = 0, roop = 0, initial = 0;
    c[counter] = 0;
    b[0] = counter;
    //printf("%d : %d\n", 0, c[0] + 1);
    while(1){
        c[counter + 1] = a[c[counter]];
        if(b[c[counter + 1]] == INT_MAX){
            b[c[counter + 1]] = counter + 1;
        }
        else{
            //printf("%d : %d\n", counter + 1, c[counter + 1] + 1);
            //printf("%d : %d    %d\n", counter + 1, c[counter + 1] + 1, b[c[counter + 1]]);
            roop = counter + 1 - b[c[counter + 1]];
            //cout << "かぶっているのは" << c[counter + 1] + 1<< endl;
            initial = b[c[counter + 1]];
            //printf("%d - %d\n", counter + 1, b[c[counter + 1]]);
            
            break;
        }
       //printf("%d : %d    %d\n", counter + 1, c[counter + 1] + 1, b[c[counter + 1]] + 1);
        counter++;
    }

    if(k > initial){
        //cout << c[(k - initial + 1)%roop + initial] + 1 << endl;
       // cout  << (k - initial)%roop << endl;
        //cout << roop << endl;
        cout << c[(k - initial)%roop + initial] + 1 << endl;
    }
    else{
        cout  << c[k] + 1<< endl;
    }

    return 0;
}