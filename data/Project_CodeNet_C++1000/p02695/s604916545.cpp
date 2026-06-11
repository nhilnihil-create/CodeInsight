#include<iostream>
#include<stack>
#include<vector>
//saw editional

class states{
    public:
    unsigned int state;
    unsigned int len;
    unsigned int numBar;
    states(unsigned int state,unsigned int len,unsigned int numBar){
        this->state=state;
        this->len=len;
        this->numBar=numBar;
    }
};

int main(){
    int N,M,Q;
    std::cin>>N>>M>>Q;
    std::vector<std::vector<int> >q(Q,std::vector<int>(4));
    for(int i=0;i<Q;++i){
        for(int j=0;j<4;++j){
            std::cin>>q[i][j];
        }
        q[i][0]-=1;
        q[i][1]-=1;
    }
    std::stack<states> st;
    std::vector<unsigned int> searchStates;
    st.push(states(0,0,0));
    while (st.size()>0){
        states calcState=st.top();
        st.pop();
        unsigned int state=calcState.state;
        unsigned int len=calcState.len;
        unsigned int numBar=calcState.numBar;
        if(numBar<N){
            states buf=states(state | 0x00001 << len,len+1,numBar+1);
            if(buf.len==N+M-1){
                searchStates.push_back(buf.state);
            }else{
                st.push(buf);
            }
        }
        if(len-numBar<M-1){
            states buf=states(state,len+1,numBar);
            if(buf.len==N+M-1){
                searchStates.push_back(buf.state);
            }else{
                st.push(buf);
            }
        }
    }
    int maxScore=-1;
    for(auto searchState:searchStates){
        std::vector<int> buf;
        int scorebuf;
        int cnt=0;
        for(int i=0;i<N+M-1;++i){
            if(searchState & 0x0001<<i){
                buf.push_back(cnt+1);
            }else{
                cnt++;
            }
        }
        scorebuf=0;
        for(int i=0;i<Q;++i){
            if(buf[q[i][1]]-buf[q[i][0]]==q[i][2]){
                scorebuf+=q[i][3];
            }
        }
        if(maxScore<scorebuf){
            maxScore=scorebuf;
        }
    }
    std::cout<<maxScore<<std::endl;
}
