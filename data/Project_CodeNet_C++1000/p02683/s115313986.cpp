#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using vivi=vector<vi>;

int main(){
    int N,M,X;
    scanf("%d%d%d",&N,&M,&X);
    vivi book(N,vi(M+1));
    int mi=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M+1;j++)
        {
            cin>>book.at(i).at(j);
            
        }
    }
    

    bool bl=true;

    int sum=0;
   
        if(bl)
        {
            
            for(int tmp=0;tmp<(1<<N);tmp++)
            {
                bitset<12> wi(tmp);
                int current=0;
                queue<int> qi;//やはりフローチャートは書くべき
                for(int i=0;i<N;i++){
                    if(wi.test(i))
                    {
                        qi.push(i);
                        current+=book.at(i).at(0);
                    }
                }
                bool over=true;
                auto memo=qi;
                if(mi==0||current<mi){
                    for(int i=1;i<M+1;i++)
                    {
                        qi=memo;
                        sum=0;
    
                        while(!qi.empty())
                        {
                            
                            sum+=book.at(qi.front()).at(i);
                            
                            qi.pop();
                        }
                      
                        if(sum<X){
                 
                            over=false;
                            break;
                        }

                        
                    }
                    if(over)
                    {
                       
                        
                        mi = current;
                       
                    }
                    
                }
                               
            }
            if(mi!=0)
            {
                cout<<mi<<endl;
            }
            else
            {
                cout<<-1<<endl;
            }
       }    
      
}