#include <iostream>
#include <map>
using namespace std;

int n, arr[100005], diff=0, x, y=1;
map<int, int> ar;
bool check=false;
int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x;
        if(x==0){
            check=true;
        }
        if(ar[x]==0){
            ar[x]++;
            diff++;
            arr[y]=x;
            y++; 
        }
        else{
            ar[x]++;
        }
    }
    if(n%3!=0){
        if(diff==1 && check==true){
            cout << "Yes" << endl;
            return 0;
        }
        else{
            cout << "No" << endl;
            return 0;
        }
    }
    else{
        if(diff==1 && check==true){
            cout << "Yes" << endl;
            return 0;
        }
        else if(diff==2 && check==true && ar[0]==n/3){
            cout << "Yes" << endl;
            return 0;
        }
        else if(diff==3){
            if(((arr[1]^arr[2])^arr[3])==0 && ar[arr[1]]==n/3 && ar[arr[2]]==n/3){
                cout << "Yes" << endl;
                return 0;
            }
            else{
                cout << "No" << endl;
                return 0;
            }
        }
        else{
            cout << "No" << endl;
            return 0;
        }
    }
}