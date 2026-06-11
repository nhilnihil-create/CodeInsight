#include<iostream>
#include<stack>
using namespace std;

int main(){
    //freopen ("/Users/shitian/Downloads/1173-in1.txt","r",stdin);
    char f[102];int c=0,d=0;
    while(1){
        stack<char>s;
        c=0;d=0;
        cin.getline (f,156);
        if(f[0]=='.')
            return 0;
        for(int i=0;f[i]!='.';i++){
            if(f[i]=='('){
                c++;s.push('(');
            }
            if(f[i]==')'){
                c--;
                if(s.size()==0){
                    cout<<"no"<<endl;
                    goto next;
                }
                if(s.top()!='('){
                    cout<<"no"<<endl;
                    goto next;
                }
                s.pop();
            }
            if(f[i]=='['){
                d++;s.push('[');
            }
            if(f[i]==']'){
                if(s.size()==0){
                    cout<<"no"<<endl;
                    goto next;
                }
                if(s.top()!='['){
                    cout<<"no"<<endl;
                    goto next;
                }
                d--;
                s.pop();
            }
            if(c<0||d<0){
                cout<<"no"<<endl;
                goto next;
            }
        }
        if(c==0&&d==0)
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;next:;
    }
    return 0;
}