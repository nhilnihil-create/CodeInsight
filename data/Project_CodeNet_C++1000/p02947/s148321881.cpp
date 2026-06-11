/*
ID: learnin7
TASK: test
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
        
    ios_base::sync_with_stdio(0);
    //ofstream fout ("test.out");
    //ifstream fin ("test.in");
    //fin >> a >> b;
    //fout << a+b << endl;
    int n;
    cin>>n;
    //vector<string> a(n);
    //set<string> x;
    unordered_map<string, int> x;
    ll cnt=0;
    for(int i=0;i<n;i++){
        string a;
        cin>>a;
        //cout<<"Original string: "<<a<<endl;
        sort(a.begin(), a.end());
        //cout<<"Sorted string: "<<a<<endl;
        if(x[a]){
          //  cout<<a<<" appeared "<<x[a]<<" times before\n";
            cnt += x[a];
            //cout<<"New count: "<<cnt<<endl;
            x[a]++;
           // cout<<"Current value: "<<x[a]<<endl;
        }
        else{
           // cout<<"First appearance\n";
            x[a]=1;
           // cout<<"Current value: "<<x[a]<<endl;
        }
    }
    cout<<cnt<<endl;
    /*
    ll c=0;
    for(int i=0;i<n;i++){
        string x = a[i];
        //cout<<"For string: "<<x<<endl;
        vector<int> cnt(26,0);
        for(int j=0;j<x.length();j++)   cnt[x[j]-'a']++;   
        //cout<<"Count array: \n";
        //for(int j=0;j<26;j++)   cout<<cnt[j]<<" ";
        //cout<<"\n";
        for(int j=0;j<n;j++){
            if(i==j)    continue;
            //cout<<"--- Checking for: "<<a[j]<<endl;
            string y = a[j];
            vector<int> res(26,0);
            bool flag=true;
            for(int k=0;k<y.length();k++){
                if(cnt[y[k]-'a']==0) {
                //    cout<<"---- No such char\n";
                    flag = false;
                    break;
                }
                if(res[y[k]-'a'])   res[y[k]-'a']--;
                else                res[y[k]-'a'] = cnt[y[k]-'a']-1; 
            }
            if(flag){ 
                //cout<<"Res array: \n";
                //for(int k=0;k<26;k++)   cout<<res[k]<<" ";
                //cout<<"\n";
            
                for(int k=0;k<26;k++){
                    if(res[k]!=0){
                  //      cout<<"----Extra or Less chars\n";
                        flag = false;
                        break;    
                    }
                }
            }
            if(flag){
                c++;
            }
        }
    }
    cout<<c/2<<endl;
    */
    return 0;
}

